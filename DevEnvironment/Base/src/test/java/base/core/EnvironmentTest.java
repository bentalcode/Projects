package base.core;

import base.interfaces.IStringTransformer;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The EnvironmentTest class implements tests for an environment.
 */
public final class EnvironmentTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The EnvironmentTest constructor.
     */
    public EnvironmentTest() {
    }

    /**
     * Tests the logic of expanding system properties.
     */
    @Test
    public void testExpandSystemProperties() {
        IStringTransformer transformer = Environment.operatingSystemTransformer();

        String str1 = Environment.isWindows() ? "a\\${os.name}\\b\\c\\d\\${os.name}" : "a/${os.name}/b/c/d/${os.name}";
        String result1 = Environment.isWindows() ? "a\\windows\\b\\c\\d\\windows" : "a/unix/b/c/d/unix";

        String str2 = Environment.isWindows() ? "a1\\b1${os.name}b2\\c1c2\\d1${os.name}d2" : "a1/b1${os.name}b2/c1c2/d1${os.name}d2";
        String result2 = Environment.isWindows() ? "a1\\b1windowsb2\\c1c2\\d1windowsd2" : "a1/b1unixb2/c1c2/d1unixd2";

        this.testExpandingSystemProperties(str1, transformer, result1);
        this.testExpandingSystemProperties(str2, transformer, result2);
    }

    /**
     * Tests the logic of expanding system properties.
     */
    private void testExpandingSystemProperties(
        String str,
        IStringTransformer transformer,
        String expectedResult) {

        String result = Environment.expandSystemProperties(str, transformer);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of system property.");
    }
}
